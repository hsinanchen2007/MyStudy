### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int s = target/2 +1;  //最大能取到的值
        int t = 0;
        // int R[][] = new int[s][s];

        List<int[]> list = new ArrayList<>();

        //第一次写的，运算超出时间限制
        // for (int i=1 ; i<=s ; i++){
        //     //对每个数都计算后面的若干个数字和它相加是否等于target
        //     for (int n=i ; n<=s ; n++){
        //         if ((n-i+1)*i + (n-i+1)*(n-i)/2 == target){

        //             //等于target时将这串数字赋值给临时数组
        //             int[] temp = new int[n-i+1];
        //             for (int j=0 ; j<n-i+1 ;j++){
        //                 temp[j] = i+j;
        //                 // R[t][j] = i+j;
        //             }
        //             list.add(temp);    
        //             // t++;
        //         }                   
        //     }
        // }

        for (int i=1,j=1,sum=0 ; j<s+1 ; j++){
            sum = sum + j;
            while(sum > target){
                sum = sum - i;
                i++;
            }//不用if因为不是只减一次，若sum比target大要减去所有前面的，向后继续扫描
            
            if (sum == target){
                int[] temp = new int[j-i+1];
                for (int a=0 ; a<j-i+1 ; a++)
                    temp[a] = i+a;
                list.add(temp);
            }
        }


        int[][] res = new int[list.size()][]; //只定义行数
        //在二位数组中，如果直接调用b.length方法，返回的则是b数组的行数，
        for (int i = 0; i < res.length; i++) {    
            res[i] = list.get(i);
        }
        return res;

    }
}
```