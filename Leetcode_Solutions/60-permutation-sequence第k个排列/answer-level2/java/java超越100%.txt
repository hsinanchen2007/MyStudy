![image.png](https://pic.leetcode-cn.com/772e94e37daa4e6467c8acfc3cdeadf8b3bfc8cadcec3a89634d93a26e389b7e-image.png)
两个循环大家都懂， down从1开始，up从当前元素的阶乘开始，如果此次循环中判断k值（也就是我们要获取的第k个全排列）在down 和 up 之间，那就说明此次循环 i 的值就是暴力全排列的外层循环次数，以此可以确定当前位置的数字，以此递推我们可以取得k位置排列的所有元素，最终得到需要的排列

class Solution {
    public String getPermutation(int n, int k) {

        boolean[] flag = new boolean[n];
        StringBuilder stringBuilder = new StringBuilder();
        int up=0,down=0;
        int[] factor = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(flag[j])continue;
                down = up+1;
                up += factor[n-1-i];
                if(down > k){
                    break;
                }
                if(k >= down && k <= up)
                {
                    stringBuilder.append(String.valueOf(j+1));
                    flag[j] = true;
                    break;
                }
                
            }
            up = down-1;
        }
        return stringBuilder.toString();
    }
}