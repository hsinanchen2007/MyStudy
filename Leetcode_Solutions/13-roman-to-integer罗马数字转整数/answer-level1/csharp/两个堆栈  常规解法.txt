```
        public static int RomanToInt(string s)
        {
            var chars = new char[] {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
            var nums = new int[] {1, 5, 10, 50, 100, 500, 1000};
            // 字符的栈
            var stacks = new Stack<char>();
            var valueStacks = new Stack<int>();
            
            
            for (int i = 0; i < s.Length; i+=1)
            {
                var ch = s[i];
                var vindex = Array.FindIndex(chars, ich=>ich == ch);
                var value = nums[vindex];

                if (stacks.Count == 0)
                {
                    //上到栈顶
                    valueStacks.Push(value);
                }
                else
                {
                    var top = stacks.Peek();
                    var topIndex = Array.FindIndex(chars, ich=>ich == top);
                    var topValue = nums[topIndex];
                    if (topIndex < vindex  )
                    {
                        var vTopValue = valueStacks.Pop();
                        valueStacks.Push(value - vTopValue);
                    }
                    else
                    {
                        valueStacks.Push(value);
                    }
                    
                }
                stacks.Push(ch);
            }

            int result = 0;
            foreach (var VARIABLE in valueStacks)
            {
                result += VARIABLE;
            }
        
            
            
            return result;
        }
```
