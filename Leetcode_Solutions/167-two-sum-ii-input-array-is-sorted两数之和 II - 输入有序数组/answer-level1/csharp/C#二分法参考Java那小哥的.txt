```
    public int[] TwoSum(int[] numbers, int target)
    {
        int[] res = null;
        int findNum, findResult, numbersMaxIndex = numbers.Length - 1;

        int BinaryFind(int[] numbers2, int start, int end, int target2)
        {
            int midIndex = 0, midValue = 0;
            while (start <= end)
            {
                midIndex = (start + end) / 2;
                midValue = numbers2[midIndex];
                if (midValue == target2)
                {
                    return midIndex;
                }
                else if (midValue < target2)
                {
                    start = midIndex + 1;
                }
                else
                {
                    end = midIndex - 1;
                }
            }

            return -1;
        }

        for (int i = 0; i <= numbersMaxIndex; i++)
        {
            findNum = target - numbers[i];
            findResult = BinaryFind(numbers, i + 1, numbersMaxIndex, findNum);
            if (findResult != -1)
            {
                res = new int[] { i + 1, findResult + 1 };
            }
        }

        return res;
    }
```

