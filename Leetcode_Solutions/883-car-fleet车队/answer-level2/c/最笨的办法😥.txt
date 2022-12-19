```c
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) {
        return 0;
    }
    int count = 1;
    int temp;
    for (int i = positionSize - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (position[j] < position[j + 1]) {
                temp = position[j];
                position[j] = position[j + 1];
                position[j + 1] = temp;
                temp = speed[j];
                speed[j] = speed[j + 1];
                speed[j + 1] = temp;
            }
        }
    }
    double markTime = (double)(target - position[0]) / (double)speed[0];
    for (int i = 1; i < positionSize; i++) {
        if (((double)(target - position[i]) / (double)speed[i] - markTime) > 0.000001) {
            markTime = (double)(target - position[i]) / (double)speed[i];
            count++;
        }
    }
    return count;
}
```
