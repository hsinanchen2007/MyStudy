### 解题思路
因为这是个数列。
这叫要用到求和公示了。
首项加末项乘以项数除以2
![image.png](https://pic.leetcode-cn.com/0caa5ab4a8f46653051e392799668de2ff860c0c1a4e733ecbb0ce5c2aeb9156-image.png)
化简一下。（不写了比较简单）
a_1=target/n+(n−1)/2
![image.png](https://pic.leetcode-cn.com/37e939465de484fa31fa5e72cb3df9953b68af02a73c9fddbe7de73b7e76fe66-image.png)
把这个式子化为计算机代码。
因为java中不存在变长数组，所以使用ArrayList，可以用add的方法向其中加入更新后的数组。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        float a=0;//符合规定的正整数序列中第一个是什么值
        float n=1;//符合规定的正整数序列中有几项
        ArrayList<int []> ids=new ArrayList<>();
        while(n<target){//
            a=((target/n)-(n-1)/2);//就是这句
            if(a%1==0&&a!=target){
                if(a<1){
                    break;
                }
                int [] arr=new int[(int) n];
                for(int i=0;i<n;i++){//因为序列的属性，每次比上一次加1可以考这种方式生成要求的正整数序列（数组）。
                    arr[i]=(int)a+i;
                }
                ids.add(arr);
            }
            n++;
        }
          Collections.reverse(ids);
        int[][] result=ids.toArray(new int[0][]);
          return result;
    }

    // public static void main(String[] args) {
    //     Solution solution = new Solution();
    //     System.out.println(solution.findContinuousSequence(9));
    // }
}
```