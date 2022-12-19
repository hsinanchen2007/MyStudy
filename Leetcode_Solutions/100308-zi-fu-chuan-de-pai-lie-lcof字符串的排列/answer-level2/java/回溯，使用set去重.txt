题目类似于全排列。
这种题目基本上都是采用回溯的套路。
主要有几点需要注意：
1:for循环的起始位置。如果需要乱序，那么就是从0开始，如果每次都是顺序查找（不需要往前找），那么就需要有个start
2:标记数组。通过标记才能让递归后的代码知道之前用过哪些市局，就可以舍去这些数字。
```
    Set<String> result = new HashSet<>();
    public String[] permutation(String s) {
        if(s == null) return new String[]{};
        boolean[] visited = new boolean[s.length()];
        process(s, "", visited);
        return result.toArray(new String[result.size()]);
    }

    private void process(String s, String letter, boolean[] visted){
        if(s.length() == letter.length()){
            result.add(letter);
            return;
        }
        for(int i = 0; i < s.length(); i++){
            char temp = s.charAt(i);
            if(visted[i]) continue;
            visted[i] = true;
            process(s, letter + String.valueOf(temp), visted);
            visted[i] = false;
        }
    }
```
