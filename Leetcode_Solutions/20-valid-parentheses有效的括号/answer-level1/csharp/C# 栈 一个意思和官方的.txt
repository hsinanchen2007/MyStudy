if (s.Length == 0) return true;
            if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
            if (s.Length % 2 == 1) return false;

            Stack<Char> stack = new Stack<Char>();
            foreach (var i in s)
            {
                if (i == '(' || i == '{' || i == '[')
                {
                    stack.Push(i);
                }
                else if(i==')')
                {
                    if (stack.Pop() != '(')
                        return false;
                }
                else if (i == '}')
                {
                    if (stack.Pop() != '{')
                        return false;
                }
                else if (i == ']')
                {
                    if (stack.Pop() != '[')
                        return false;
                }
            }
            return stack.Count == 0;