int tribonacci(int n)
{
    int array[100] = {0};
    array[0] = 0;
    array[1] = 1;
    array[2] = 1;

    for(int i = 3; i < 38; i++) {
        array[i] = array[i - 3] + array[i - 2] + array[i - 1];
    }

    return array[n];
}