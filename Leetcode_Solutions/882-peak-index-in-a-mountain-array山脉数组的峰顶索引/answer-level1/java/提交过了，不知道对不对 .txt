class Solution {
    public int peakIndexInMountainArray(int[] A)
    {   int num =0;
        for(int i =0;i<A.length-1;i++)
        {
            if (A[i]>A[i+1])
            {
                num =i;
                break;
            }
        }
        return num;
    }
}

根据山脉数组特性，既然已经确定数组的特点，直接找到值大于后一个值的位置，输出它即可