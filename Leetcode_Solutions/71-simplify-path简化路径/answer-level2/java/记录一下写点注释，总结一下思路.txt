### 解题思路
。
时间复杂度应该是o（n）,空间复杂度也是o（n）

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        // 边界判断输入为空或者长度为1时可直接输出
        if (path.length() == 0 || path == null || path.length() == 1) {
            return "/";
        }
        int i = 0; // 用于记录当前读取到path的哪个位置了
        List<Character> temp = new ArrayList<>();// 用于存放当前已经得到的目录结果
        // 如果一开始就有很多/就一直往后找直到找到一个不等于/的位置
        while (path.charAt(i) == '/' ) {
            i ++;
            if (i >= path.length()) {
                return "/";
            }
        }
        // 为了应对path结尾不是/的情况，添加一个/规避结尾是..或者.，如果是这两种情况结尾不加/就需要在最后做判断然后出栈或者留在当前目录，就会很麻烦。加了/之后如果结尾是..或者.就可以读取到/对前面的..或者.进行响应的操作。
        if (!path.substring(path.length() - 1).equals("/")) {
            path = path + "/";
        }
        // 给最终目标结果暂存值存一个/开头
        temp.add('/');
        int state = 0; // 表示当前读取字符串的状态，如果state=0就表示当前不是那种需要退栈（../）或者留在原目录（./）的情况，如果state等于1，表明当前读到了一个.,如果state等于2，表明当前读到了两个.
        while (true) {
            if (state == 1 && path.charAt(i) == '.') {
                // state=1，当前读到了一个.，如果下一个还是.就要state=2了
                temp.add('.');
                state = 2;
                i ++;
                // 如果找的过程中到了path尽头就退出
                if (i >= path.length()) {
                    break;
                }
            } else if (state == 1 && path.charAt(i) == '/') {
                temp.remove(temp.size() - 1);
                state = 0;
                while (path.charAt(i) == '/') {
                    i ++;
                    if (i >= path.length()) {
                        break;
                    }
                }
                if (i >= path.length()) {
                    break;
                }
            } else if (state == 1) {
                temp.add(path.charAt(i));
                state = 0;
                i ++;
                if (i >= path.length()) {
                    break;
                }
            }
            if (state == 2 && path.charAt(i) == '/') {
                temp.remove(temp.size() - 1);
                temp.remove(temp.size() - 1);
                state = 0;
                if (temp.size() != 1) {
                    temp.remove(temp.size() - 1);
                }
                while (temp.get(temp.size() - 1) != '/') {
                    temp.remove(temp.size() - 1);
                }
                while (path.charAt(i) == '/') {
                    i ++;
                    if (i >= path.length()) {
                        break;
                    }
                }
                if (i >= path.length()) {
                    break;
                }
            } else if (state == 2 && path.charAt(i) == '.') {
                temp.add('.');
                state = 0;
                i ++;
                if (i >= path.length()) {
                    break;
                }
            } else if (state == 2) {
                state = 0;
                temp.add(path.charAt(i));
                i ++;
                if (i >= path.length()) {
                    break;
                }
            }
            if (state == 0 && path.charAt(i) == '.') {
                state = 1;
                temp.add('.');
                i ++;
                if (i >= path.length()) {
                    break;
                }
            } else if (state == 0 && path.charAt(i) == '/') {
                temp.add(path.charAt(i));
                while (path.charAt(i) == '/') {
                    i ++;
                    if (i >= path.length()) {
                        break;
                    }
                }
                if (i >= path.length()) {
                    break;
                }
            } else if (state == 0) {
                temp.add(path.charAt(i));
                i ++;
                if (i >= path.length()) {
                    break;
                }
            }
            if (i >= path.length()) {
                break;
            }
        }
        while (temp.get(temp.size() - 1) == '/' && temp.size() != 1) {
            temp.remove(temp.size() - 1);
        }
        StringBuilder result = new StringBuilder();
        for (int j = 0; j < temp.size(); j++) {
            result.append(temp.get(j));
        }
        return result.toString();

    }
}
```