            1. 在这之前尝试了一下用数组排序，然后自己写的双重循环失败了（提交超时）.....
            2. 然后也折腾了一下直接去判断结果数组中最大值替换，结果被多个同样的最小值打脸，获取的永远都是最小的N个，或者一堆0...
            1. 在这之前尝试了一下用数组排序，然后自己写的双重循环失败了（提交超时）.....
            2. 然后也折腾了一下直接去判断结果数组中最大值替换，结果被多个同样的最小值打脸，获取的永远都是最小的N个，或者一堆0...
            3. 然后用这种奇葩方法解决了。奇葩在于循环当前数组，构建一个字典，然后根据数组的key排序，最后根据需要的k的数量进行处理（以为这个办法才是最麻烦的，会超时的...结果没有）
```
 public int[] GetLeastNumbers(int[] arr, int k) {
 var result = new int[k];
            var a = arr.Min();
            if (k == 1)
            {
                result[0] = a;
            }
          
            Dictionary<int, int> dic = new Dictionary<int, int>();
            foreach (var item in arr)
            {
                int count = 0;
                if (dic.TryGetValue(item, out count))
                {
                    dic[item] = ++count;
                }
                else
                {
                    dic.Add(item, 1);
                }
            }
            var aaa = dic.OrderBy(t => t.Key);
            int index = 0;
            foreach (var item in aaa)
            {
                if (item.Value > k)
                {
                    for (int i = index; i < k - index; i++)
                    {
                        result[i] = item.Key;
                    }
                    break;
                }
                else
                {
                    var count = index + item.Value > k ? k : index + item.Value;
                    for (int j = index; j < count; j++)
                    {
                        result[j] = item.Key;
                    }
                    index = count;
                }
            }
            return result;
    }
```

