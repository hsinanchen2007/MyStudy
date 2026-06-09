public string RemoveDuplicates(string S) {
        Stack<Char> sc = new Stack<char>();
            for(int i=0;i<S.Length;i++)
            {
                if (sc.Count== 0)
                    sc.Push(S[i]);
                else if(sc.Peek()!=S[i])
                    sc.Push(S[i]);
                else
                    sc.Pop();
            }
            return string.Join("",sc.Reverse());
    }