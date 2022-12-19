            string left = "{([";
            string right = "})]";

            if (string.IsNullOrEmpty(s))
            {
                return true;
            }

            if (left.IndexOf(s[0]) < 0 || s.Length%2 == 1)
            {
                return false;
            }

            Stack<char> stack = new Stack<char>();

            foreach (var item in s)
            {
                if (left.IndexOf(item) >= 0)
                {
                    stack.Push(item);
                }
                else if (item == ')')
                {
                    if(stack.Peek() == '(')
                    {
                        stack.Pop();
                    }
                    else
                    {
                        stack.Push(item);
                    }
                }
                else if (item == ']')
                {
                    if (stack.Peek() == '[')
                    {
                        stack.Pop();
                    }
                    else
                    {
                        stack.Push(item);
                    }
                }
                else if (item == '}')
                {
                    if (stack.Peek() == '{')
                    {
                        stack.Pop();
                    }
                    else
                    {
                        stack.Push(item);
                    }
                }
            }

            return stack.Count == 0;