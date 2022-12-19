            Stack<char> stack1 = new Stack<char>();
            foreach (char item in s)
            {
                if (item != '#')
                {
                    stack1.Push(item);
                    continue;
                }

                if (stack1.Count > 0)
                {
                    stack1.Pop();
                }
            }


            Stack<char> stack2 = new Stack<char>();
            foreach (char item in s)
            {
                if (item == '#' && stack2.Count > 0)
                {
                    stack2.Pop();
                }
                else
                {
                    stack2.Push(item);
                }
            }

            if (stack1.Count != stack2.Count)
            {
                return false;
            }

            while (stack1.Count > 0)
            {
                char item1 = stack1.Pop();
                char item2 = stack2.Pop();
                if (item1 != item2)
                {
                    return false;
                }
            }
            return true;