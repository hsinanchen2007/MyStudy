```
    public void DuplicateZeros(int[] arr)
    {
        Queue<int> queue = new Queue<int>();
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] != 0)
            {
                queue.Enqueue(arr[i]);
            }
            else
            {
                queue.Enqueue(arr[i]);
                queue.Enqueue(arr[i]);
            }
        }
        int startIndex = 0;
        while (queue.Any() && (startIndex < arr.Length))
        {
            var cur = queue.Dequeue();
            arr[startIndex++] = cur;
        }
    }
```
