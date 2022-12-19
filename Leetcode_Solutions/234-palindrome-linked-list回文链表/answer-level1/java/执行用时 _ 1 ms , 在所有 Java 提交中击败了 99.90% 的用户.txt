
# 感觉方法比较笨，不会用链表比较，直接把元素插入数组中，在数组中比较。       

**首先通过遍历得到链表的长度**
```
ListNode p1 = head;
int size = 0;
        for(int i = 1 ; p1 != null ; p1 = p1.next, i++){
            size = i;
        }
```

**声明一个数组（数组大小为链表的长度），将链表中元素依次插入数组中**
```
        int[] a = new int[size];
        for(int i = 0 ; head != null ; head = head.next, i++){
            a[i] = head.val;
        }
```

**判断数组中是否回文比较简单，依次比第一个元素的最后一个元素，如果有不一样的直接返回false**
```
        int j = size;
        for(int i = 0; i < size/2; i++,j--){
            if(a[i] != a[j-1]){
                return false;
            }
        }
        return true;
    }
```
