        long long sum = 0;
        long long total = 0;
        long long size = (long long)A.size();

        for (int i = 0; i < size; i++)
        {
            sum += i * A[i];
            total += A[i];
        }

        auto lastInd = size - 1;
        auto maxSum = sum;
        for (int i = 1; i < (int)A.size(); i++)
        {
            sum += total - size * A[lastInd];
            lastInd--;

            if (maxSum < sum)   maxSum = sum;
        }

        return maxSum;