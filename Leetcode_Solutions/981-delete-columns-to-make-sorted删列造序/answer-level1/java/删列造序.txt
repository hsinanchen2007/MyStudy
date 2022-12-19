```java
class Solution {
    public int minDeletionSize(String[] A) {
        int rowLen = A.length;
        if(rowLen <=0 )
            return 0;
        int colLen = A[0].length();
        char[][] B = new char[colLen][rowLen];
        //将A 按照列放到B中
        for(int i=0;i<rowLen;i++){
            for(int j=0;j<colLen;j++){
                char c = A[i].charAt(j);
                B[j][i] = c;
            }
        }
        //打印B数组进行验证
        // for(int i=0;i<colLen;i++){
        //     for(int j=0;j<rowLen;j++){
        //         System.out.print(B[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        //对B进行逐行遍历，如果该行不是非降序的，则ans++
        int ans = 0;
        for(int i=0;i<colLen;i++){
            int temp = B[i][0] - 'a';
            for(int j=1;j<rowLen;j++){
                int cur = B[i][j] - 'a';
                if(cur<temp){
                    ans++;
                    break;
                }
                temp = cur;
            }
        }
        return ans;
    }
}