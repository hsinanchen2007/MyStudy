### 解题思路
主要的思路就是建立一个很大的数组，先把整个数组全部遍历一遍，统计每个数出现的次数。
然后遍历这个数组
1、如果数值为1，说明这个数字是唯一的
2、如果数值比1大，说明这个数字是重复的，那么我就使用一个list来存储一下后续需要改变的数
3、如果数值为0,说明这个数字在原来A中没有出现，那么如果之前list数组里面有重复的数字的话，我们可以取出list中的第一个元素让他变成当前的这个数，这样的代价肯定是最小的。

我使用sum来统计需要move的次数，使用count来统计多少个数字已经处理过变得唯一。

一开始数组长度设置为40001,发现答案错误，于是设置为50001
这是因为可能数组最后面很大的数字重复，这样可能需要改变到40000之后的数字才可能，所以不宜设置为40001

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A==null||A.length==0){
            return 0;
        }
        int[] arr = new int[50001];
        int len = A.length;
        Arrays.sort(A);
        int min = A[0];
        for(int i = 0; i < A.length; i++){
            arr[A[i]]++;
        }
        int sum = 0;
        int count = 0;
        LinkedList<Integer> list = new LinkedList();
        for(int i = A[0]; i <50001; i++){
            if(count==len){
                break;
            }
            if(arr[i]==1){
                count++;
                continue;
            }
            if(arr[i]>1){
                int n = arr[i] - 1;
                while(n>0){
                    list.add(i);
                    n--;
                }
                count++;
            }
            if(arr[i]==0){
                if(!list.isEmpty()){
                    int num = list.get(0);
                    list.removeFirst();
                    sum += i - num;
                    count++;
                }
                
            }
        }
        return sum;
    }
}
```