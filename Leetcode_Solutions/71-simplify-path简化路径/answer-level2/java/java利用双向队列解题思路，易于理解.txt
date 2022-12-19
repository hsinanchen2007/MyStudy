```
public String simplifyPath(String path) {
        String[] record = path.split("/");
         Deque<String> dir = new LinkedList<>();
        for(int i = 0;i < record.length; i++){
            if(record[i].equals("") || record[i].equals(".")){ //将分隔后的结果为 "."或者空的直接忽略
                continue;
            }else if(record[i].equals("..")){ //为".."的，说明是上一级目录，弹出一个目录
                if(dir.size() != 0){ // 如果栈为空，说明是根目录，不能继续弹出
                    dir.pop();
                }
            }else{
                dir.push(record[i]);// 分隔后的结果为目录的，压入栈中作为目录
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append("/");
        if(dir.size() == 0){ //如果此时栈为空，说明此时在根目录，直接返回"/"
            return sb.toString();
        }
        while(dir.size() != 0){
            sb.append(dir.removeLast()); //从队列的尾部取目录进行拼接
            sb.append("/");
        }
        sb.delete(sb.length()-1,sb.length());
        return sb.toString();
    }
```