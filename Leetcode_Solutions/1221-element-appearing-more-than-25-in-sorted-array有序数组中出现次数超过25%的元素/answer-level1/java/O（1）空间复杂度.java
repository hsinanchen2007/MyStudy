```
class Solution {
    public int findSpecialInteger(int[] arr) {
        int cnt = 0;
        int i = 0;
        int num = arr[0];
    
        while (i < len)
        {
            cnt = 0;
            while (arr[i] == num)
            {
                cnt++;
                //题目保证只有一个数满足条件
                if (cnt >= arr.length / 4 + 1)
                    return num;
                i++;
            }
            //更新
            num = arr[i];
        }
            
        return num;
    }
}
```
时间复杂度 O（N）, 空间复杂度O（1），主要是利用题干的"有序"条件