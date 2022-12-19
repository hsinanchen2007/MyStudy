```
char** fizzBuzz(int n, int* returnSize)
{
    char* fizz = malloc(5);
    char* buzz = malloc(5);
    char* fizzbuzz = malloc(9);
    sprintf(fizz, "%s", "Fizz");
    sprintf(buzz, "%s", "Buzz");
    sprintf(fizzbuzz, "%s", "FizzBuzz");
    char** res = (char**)malloc(sizeof(char*) * n);
    *returnSize = n;
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0)      res[i - 1] = fizzbuzz;
        else if (i % 5 == 0)  res[i - 1] = buzz;
        else if (i % 3 == 0)  res[i - 1] = fizz;
        else {
            res[i - 1] = malloc(10);
            sprintf(res[i - 1], "%d", i);
        }
    }
    return res;
}
```
由于fizz，buzz，fizzbuzz可以重复利用，所以可以事先构造好，然后直接将地址赋给res即可。这样可以省去利用sprintf重复复制的工作。