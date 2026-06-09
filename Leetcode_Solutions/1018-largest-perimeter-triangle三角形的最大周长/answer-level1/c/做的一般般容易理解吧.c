int cmpInt(const void *a, const void *b)
{
    return ((*(int *)b) - (*(int *)a));
}

bool isTriangle(int a, int b, int c)
{
    return ((a + b > c) && (b + c > a) && (c + a > b));
}

int largestPerimeter(int* A, int ASize)
{
    qsort(A, ASize, sizeof(int), cmpInt);

    for (int i = 0; i < ASize - 2; i++)
    {
        if (true != isTriangle(A[i], A[i+1], A[i+2])) continue;
        return (A[i] + A[i + 1] + A[i + 2]);
    }

    return 0;
}
