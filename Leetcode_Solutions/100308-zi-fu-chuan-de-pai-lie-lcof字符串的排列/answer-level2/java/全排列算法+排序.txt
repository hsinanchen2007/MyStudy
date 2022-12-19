### 解题思路
思路在这里有写，知乎大佬刷***的题解
https://zhuanlan.zhihu.com/p/103383116

### 代码

```java
class Solution {
    public String[] permutation(String s) {
        ArrayList<String> list = new ArrayList<>();
        if(s==null||s.length()==0){
            return new String[]{};
        }
        permutation(s.toCharArray(), 0, list);
        Collections.sort(list);
        String[] res=new String[list.size()];
        int index=0;
        for(int i=0;i<list.size();i++){
            res[index++]=list.get(i);
        }
        return res;
    }

    public  void permutation(char[] arr, int i, ArrayList<String> list) {
        if (i == arr.length - 1) {
            list.add(String.valueOf(arr));
        } else {
            Set<Character> set = new HashSet<>();
            for (int j = i; j < arr.length; j++) {
                if (j == i || !set.contains(arr[j])) {
                    set.add(arr[j]);
                    swap(arr, i, j);
                    permutation(arr, i + 1, list);
                    swap(arr, j, i);
                }
            }
        }
    }

    public  void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
```