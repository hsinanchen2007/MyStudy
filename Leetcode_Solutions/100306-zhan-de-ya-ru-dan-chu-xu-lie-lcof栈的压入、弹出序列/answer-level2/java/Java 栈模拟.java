```
public boolean validateStackSequences(int[] pushed, int[] popped) {
 int len=popped.length;
      int[] stack=new int[len];
      int ptr=-1; int j=0;
        for (int i = 0; i <len ; i++) {

            while (j<len&&ptr>=0&&stack[ptr]==popped[j]){ptr--;j++;}  //是否需要出栈
            stack[++ptr]=pushed[i];
        }

        while (j<len&&ptr>=0&&stack[ptr]==popped[j]){ptr--;j++;}//入栈序列遍历完，但出栈序列                                                                     没读完

        return ptr==-1;
    }
```
