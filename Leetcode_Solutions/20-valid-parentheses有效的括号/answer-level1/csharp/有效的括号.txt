c#:  

    public bool IsValid (string s) {

		Stack<char> stack = new Stack<char> ();
		foreach (char c in s) {　　
			if (c == '(')
				stack.Push (')');
			else if (c == '[')
				stack.Push (']');
			else if (c == '{')
				stack.Push ('}');
			else if (0 == stack.Count || stack.Pop () != c)
				return false;
		}
		return 0 == stack.Count;
	}
