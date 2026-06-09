### 解题思路
此处撰写解题思路
时间复杂度：O(A.length)
空间复杂度：A,i,O(2)
### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        //int flag=0;
        char []A =String.valueOf(num).toCharArray();
        for(int i=0;i<A.length;i++){
            if(A[i]=='6'){
                A[i]='9';
                //flag+=1;
                break;
            }
           // if(flag==1)
            //    break;
        }

        return Integer.parseInt(String.valueOf(A));//现将数组转换为字符串，然后转换为int型
    }
}
```