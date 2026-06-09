联想数字的全排列，数字全排列传的是int数组，这里是String
1 先把Sting.toCharArray 转化为char数组

数字全排列 用ArrayList储放子集
2 这里用StringBilder储存子集，当StingBuilder.length == char.length时 说明把所有的元素都挑完了，再把StringBuilder转化为String
放到结果中
```java []
public class Solution {
    public ArrayList<String> Permutation(String str) {
       ArrayList<String> res = new ArrayList<>();
        if(str == null || str.length() == 0){
            return res;
        }
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        HashSet<Integer> visited = new HashSet<>();
        StringBuilder sb = new StringBuilder();
        dfs(arr, res, visited, sb);
        return res;
    }
    
    private void dfs(char[] arr, ArrayList<String> res, HashSet<Integer> visited, StringBuilder sb){
        if(sb.length() == arr.length){
            res.add(new String(sb.toString()) );
            return;
        }
        
        for(int i = 0; i < arr.length; i++){
            if(visited.contains(i)){
                continue;
            }
            if(i > 0 && !visited.contains(i - 1) && arr[i] == arr[i - 1]){
                continue;
            }
            
            sb.append(arr[i]);
            visited.add(i);
            dfs(arr, res, visited, sb);
            visited.remove(i);
            sb.deleteCharAt(sb.length() -1);
        }
    }
}
```
