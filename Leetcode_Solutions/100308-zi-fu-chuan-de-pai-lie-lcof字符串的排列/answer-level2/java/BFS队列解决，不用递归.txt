基本思想：构建一棵树。例如：a的全排列为一层，ab的全排列为第二层，abc的全排列为第三层。只需取出第三层的元素并用Set去重即可。
         注意：每一层的全排列就是在上一层字符串的各个位置插入新增加的字符。
```
public String[] permutation(String s) {
        if(s.isEmpty()){
            return new String[0];
        }
        Set<String> set = new HashSet<>();
        int i;
        Queue<String> queue = new LinkedList<>();
        queue.offer(s.substring(0,1));
        while (!queue.isEmpty()){
            if(queue.peek().length() == s.length()){    //表明访问到了最后一层，从队列里全部取出进行去重
                set.addAll(queue);
                break;
            }

            String temp = queue.poll();
            i = temp.length();
            for (int j = 0; j <= temp.length(); j++) {      //在该字符串的每个空隙插入新增加的字符，并入队
                StringBuilder sb = new StringBuilder(temp);
                sb.insert(j, s.charAt(i));
                queue.offer(sb.toString());
            }
        }
        return set.toArray(new String[0]);
    }
```


