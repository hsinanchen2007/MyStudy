### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
            String[] split = path.split("/");
            StringBuilder sb = new StringBuilder();
            //压栈操作
            for (String s : split) {
                switch (s) {
                    case ".":
                        break;
                    case "..": {
                        if (sb.length() == 0) {
                            break;
                        } else {
                            sb.delete(sb.lastIndexOf("/"), sb.length());
                            break;
                        }
                    }
                    case "": {
                        break;
                    }
                    default: {
                        sb.append("/").append(s);
                    }
                }
            }
            if (sb.length() == 0){
                sb.append("/");
            }
            return sb.toString();
    }
}
```