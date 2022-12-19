
题目不难，用双指针技能完成，有些小细节，可以做一些优化操作，提升运算速度。只有两个指针所指的数相等时，才需要进行1变0,0变1的操作。




```
public int[][] FlipAndInvertImage(int[][] A) {
    for(int i =0;i<A.Length;i++){
        int x=0;
        int y=A[i].Length-1;
        while(x<=y){
            if(A[i][x]==A[i][y]){
                A[i][x]=A[i][y]=A[i][x]==0?1:0;
            }
            x++;y--;
        }
    }
    return A;
}
```
![Snipaste_2019-09-27_12-02-40.png](https://pic.leetcode-cn.com/55f098fa3a4ad15c41951660820d887253d6234593b81a88da002929fd4081e9-Snipaste_2019-09-27_12-02-40.png)




