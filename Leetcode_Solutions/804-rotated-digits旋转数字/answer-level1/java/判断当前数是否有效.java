直接判断每一位数旋转后是否有效 若有效 再判断旋转后是否与与当前位原数相等 只要遍历完成后没有无效数出现 且出现过一个旋转后不与原数相等的位数 则 + 1
```
class Solution {
    public int rotatedDigits(int N) {
        int[] isGood = new int[]{0, 1, 5, -1, -1, 2, 9, -1, 8, 6};//旋转后会变成的数
        int res = 0;
        for (int i = 2; i <= N; i ++){  //遍历每个数
            int copy = i;
            int flag = 0;  //用来记录是否出现了旋转后与原数不同的有效数
            while (copy != 0){  //遍历每个数的每一位
               int tmp = copy % 10;
               if (isGood[tmp] == - 1){  //出现无效数直接退出当前循环
                   flag = 0; 
                   break;
               }
               if (isGood[tmp] != tmp){  //旋转后与原数不同的有效数
                   flag = 1;
               }
               copy /= 10;
            }
            if (flag == 1)
                res += 1;
            
        }
        return res;
    }
    
    public static void main(String[] args) {
    	Solution s = new Solution();
    	System.out.print(s.rotatedDigits(857));
    }  
}