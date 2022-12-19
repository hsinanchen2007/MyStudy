利用LinkedList实现。
在循环中如果链表长度为0，或者链表的最后一个元素与循环中的字符相等，则将字符添加到链表末尾；
否则移除链表尾元素，并判断此时链表长度是否为0，若为0，则result++
``` java
public int balancedStringSplit(String s) {
        int result = 0;
        LinkedList<Character> list = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
            if (list.size() == 0 || list.peekLast().equals(s.charAt(i))) {
                list.add(s.charAt(i));
            } else {
                list.removeLast();
                if (list.size() == 0) {
                    result++;
                }
            }
        }
        return result;
    }
```

