### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        ArrayList<Integer> res = new ArrayList<>();
        char[] num_arr = new char[n];
        for(int i = 0;i<n;i++)
            num_arr[i] = '0';
        dfs(num_arr,res,0);
        res.remove(0);
        int[] result = res.stream().mapToInt(Integer::valueOf).toArray();
        return result;
    }

    public void dfs(char[] arr,ArrayList<Integer> res,int index){
        if(index==arr.length){
            res.add(save(arr));
            return;
        }
        for(int i = 0;i<10;i++){
            arr[index] = (char)(i+'0');
            dfs(arr,res,index+1);
        }
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
修改保存函数为打印函数即可