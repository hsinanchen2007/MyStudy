### 解题思路
![1111.png](https://pic.leetcode-cn.com/3320f80eb5c2a94d1ead7244716099bb296e07e6d44551d4cd16928c6126af5c-1111.png)

1.数组排序
2.记录每组连续数字的个数
3.把记录再排序
4.从最大数开始累加，知道大于等于数组长度一般

### 代码

```java
class Solution {
    public int minSetSize(int[] arr) {
        Arrays.sort(arr);
        ArrayList<Integer> cnt=new ArrayList<>();
        cnt.add(1);
        for (int i=1;i<arr.length;i++){
            if (arr[i]==arr[i-1])
                cnt.set(cnt.size()-1,cnt.get(cnt.size()-1)+1);
            else{
                cnt.add(1);
            }
        }
        Collections.sort(cnt);
        int num=0;
        for (int i=cnt.size()-1;i>=0;i--){
            num+=cnt.get(i);
            if (num*2>=arr.length)
                return cnt.size()-i;
        }
        return 0;
    }
}
```