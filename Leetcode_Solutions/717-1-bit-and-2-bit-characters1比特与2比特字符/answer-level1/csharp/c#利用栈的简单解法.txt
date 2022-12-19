
从前往后依次遍历，出现0就压入true，出现1压入false并且跳过下一个，遍历完弹出最顶上的值就是结果。

```
        public bool IsOneBitCharacter(int[] bits)
        {
            Stack<bool> stack = new Stack<bool>();
            for (int i = 0; i < bits.Length; i++)
            {
                stack.Push(true);
                if (bits[i] == 1)
                {
                    stack.Push(false);
                    i++;
                }
            }
            return stack.Pop();
        }
```
