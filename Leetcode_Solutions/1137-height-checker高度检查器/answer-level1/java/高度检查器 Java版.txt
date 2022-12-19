```Java []
class Solution{
    /**
    * 方法一：将数组heights里对应值赋给数组a，并对a排序，然后用a和heights作比较
    * 执行用时 :2 ms, 在所有 Java 提交中击败了95.46%的用户
    * 内存消耗 :35 MB, 在所有 Java 提交中击败了100.00%的用户
    */
    public int heightChecker1(int[] heights) {
        int len = heights.length;
        int[] a = new int[len];
        for(int i = 0; i < heights.length; i++) {
            a[i] = heights[i];
        }
        Arrays.sort(a);
        int count = 0;
        for(int i = 0; i < len; i++) {
            if (a[i] != heights[i])
                count++;
        }
        return count;
    }

    /**
    * 方法二：每个元素的索引值应该等于数组中比该元素小的个数
    * 执行用时 :2 ms, 在所有 Java 提交中击败了95.46%的用户
    * 内存消耗 :35.1 MB, 在所有 Java 提交中击败了100.00%的用户
    */
    public int heightChecker2(int[] heights) {
        int[] a = new int[101];
        //统计每个元素出现的次数
        for(int i = 0; i < heights.length; i++) {
            a[heights[i]] ++;
        }
        
        //统计错误的个数
        int count = 0;
        for(int i = 0, j = 0; i < a.length; i++) {
            while(a[i]-- > 0) {
                if(heights[j++] != i) {
                    count++;
                }
            }
        }
        return count;
    }
}
```
