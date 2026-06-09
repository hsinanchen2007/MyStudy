### 解题思路
参考的是官方解法二的思路，有人写的比我更好，我这边界的逻辑想了很久。
而且在idea上和网页调试通过，提交失败就很迷。
官方代码返回的A数组，是在类里面操作的。**我想拷贝数组，试了两个方法**都没有成功下面有注释，有人感兴趣的话研究一下教教我。。。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] tmp = new int[m+n];
        int a = 0,b = 0;
        for (int i = 0; i < m+n ; i++)
        {
            if(A[a] <= B[b])
            {
                System.out.println("A <B");
                if(a < m){
                    tmp[i] = A[a];
                    System.out.println("1A"+a);
                    a++;
                }
                else {
                    tmp[i] = B[b];
                    System.out.println("1B"+b);
                    b++;
                }
            }
            else {
                if(b < n){
                    tmp[i] = B[b];
                    System.out.println("2B"+b);
                    b++;
                }
                else{
                    tmp[i] = A[a];
                    System.out.println("2A"+a);
                    a++;
                }
            }
        }
        for (int p = 0;p<m+n;p++)
        {System.out.print(tmp[p]);}

        //两种转换方式都没成功
        //A = Arrays.copyOf(tmp,m+n);
        //System.arraycopy(A,0,tmp,0,A.length);
        for (int i = 0; i != m + n; ++i)
            A[i] = tmp[i];
    }
}

```
参考了官方解答后用JAVA实现了更简洁的表达，提交也能通过了
### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int[] tmp = new int[m+n];
        int a = 0,b = 0;
        for (int i = 0;i<m+n&&(a < m || b < n);i++){
            if(a == m)
            {
                tmp[i] = B[b];
                System.out.println("1B"+b);
                b++;
            }
            else if(b == n){
                tmp[i] = A[a];
                System.out.println("2A"+a);
                a++;
            }
            else if(A[a] <= B[b])
            {
                tmp[i] = A[a];
                System.out.println("1A"+a);
                a++;
            }
            else{
                tmp[i] = B[b];
                System.out.println("2B"+b);
                b++;
            }
        }
        //for (int p = 0;p<m+n;p++)
        //{System.out.print(tmp[p]);}

        for (int i = 0; i != m + n; ++i)
            A[i] = tmp[i];
    }
}
```
