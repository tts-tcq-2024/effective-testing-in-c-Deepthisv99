#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    if (celcius > 200) {
        return 500;
    } else {
        return 200;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;  // Bug: should increment by 1, but it does not
    }
}

int main() {
    alertInCelcius(400.5); // This should trigger a failure alert
    alertInCelcius(303.6); // This should not trigger a failure alert
    assert(alertFailureCount == 1);  // This test should fail due to incorrect error handling
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
