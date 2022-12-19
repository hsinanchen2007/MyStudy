### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        ArrayList<Integer> res = new ArrayList<>();
        char[] num_arr = new char[n+1];
        for(int i = 0;i<n+1;i++)
            num_arr[i] = '0';
        boolean up = false;
        while(num_arr[0]!='1'){

            for(int i = n;i>=0;i--){
                if(num_arr[i]<'9'){
                    num_arr[i]+=1;
                    up = false;
                    if(i!=0)
                        res.add(save(num_arr));
                    break;
                }else{
                    num_arr[i] = '0';
                    up = true;
                    continue;
                }
            }
        }
        int[] result = res.stream().mapToInt(Integer::valueOf).toArray();
        return result;
    }
    public int save(char[] arr){
        int n = 0;
        for(int i = 0;i<arr.length;i++){
            if(arr[i]!='0'){
                for(int j = i;j<arr.length;j++){
                    n = n*10+arr[j]-'0';
                }
                break;
            }
        }
        return n;
    }
}
```
剑指offer 大数题 把保存代码改成打印代码就可以符合大数要求