```C# []
        public string RemoveDuplicates(string S)
        {
            /*
             * 题目概述：删除重复相邻项
             * 
             * 思路：
             *  1.发现两个项重复,删除以后,还需要查看之前的字符与当前最新字符的关系,这种处理方式与栈的行为非常的类似,因此考虑使用栈
             *  2.依次向栈中添加元素,若发现新的元素与栈顶的元素相同,则出栈,其它情况需要入栈
             *
             * 知识点：栈 数组
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(n)
             */

            var stackTemp = new Stack<char>();
            foreach (var sItem in S)
            {
                if (!stackTemp.Any())
                {
                    stackTemp.Push(sItem);
                    continue;
                }

                if (stackTemp.Peek() == sItem)
                    stackTemp.Pop();
                else
                    stackTemp.Push(sItem);
            }

            return new string(stackTemp.Reverse().ToArray());
        }
```
