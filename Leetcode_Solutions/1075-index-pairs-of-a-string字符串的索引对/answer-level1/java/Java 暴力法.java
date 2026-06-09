```
class Solution {
    public int[][] indexPairs(String text, String[] words) {
        // 提取words元素宽度
        int size = words.length;
        Set<Integer> sizes = new TreeSet<>();
        for(int i = 0; i < size; i++) {
            sizes.add(words[i].length());
        }
        
        // 初始化动态二维数组
        ArrayList<int[]> result = new ArrayList<>();
        
        // 遍历text和字符串长度
        for (int j = 0; j < text.length(); j++) {
            for (Integer m : sizes) {
                if (j + m <= text.length()) {
                    for (String n : words) {
                        if (text.substring(j, j + m).equals(n)) {
                            int[] tmp = new int[]{j, j + m - 1};
                            result.add(tmp);
                        }
                    }   
                }
            }
        }
        
        // 将ArrayList<int[]>转化为int[][]并输出
        int len = result.size();
        int[][] out = new int[len][2];
        for (int e = 0; e < len; e++) {
            out[e] = result.get(e);
        }
        return out;
    }
}
```
