```
class Solution {
    ArrayList<String> list = new ArrayList<>();
    public int nextGreaterElement(int n) {
        String str = String.valueOf(n);
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        boolean[] used = new boolean[str.length()];
        backtrack(arr, used, new StringBuilder());
        int index = list.indexOf(str);
        if(index == list.size()-1){
            return -1;
        }
        if(Long.valueOf(list.get(index+1)) > Integer.MAX_VALUE){
            return -1;
        }
        return Integer.valueOf(list.get(index+1));
    }
    public void backtrack(char[] arr, boolean[] used, StringBuilder sb){
        if(sb.length()==arr.length){
            StringBuilder sb1 = sb;
            list.add(sb1.toString());
            return ;
        }
        for(int i=0; i<arr.length; i++){
            if(used[i]){
                continue;
            }
            if(i>0 && arr[i-1]==arr[i] && used[i-1]){
                continue;
            }
            used[i] = true;
            sb.append(arr[i]);
            backtrack(arr, used, sb);
            sb.deleteCharAt(sb.length()-1);
            used[i] = false;
        }
    }
}
```
