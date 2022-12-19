```
class Solution {
    public int heightChecker(int[] heights) {
        int[] x=new int[heights.length];
        System.arraycopy(heights,0,x,0,heights.length);
        Arrays.sort(x);
        int count=0;
        for(int i=0;i<heights.length;i++){
            if(x[i]!=heights[i]) count++;
        }
        return count;
    }
}
```
首先创建一个数组heights的副本，然后对该数组排序，然后比较两个数组不同的数字有多少个，该数字即为答案
