```csharp
public bool IsValid(string s) 
{
	if (s.Length % 2 == 1) return false;
	Stack<char> stack = new Stack<char>();
	foreach(char c in s) 
	{
		if (stack.Count == 0) stack.Push(c); else if (c - stack.Peek() == 1 || c - stack.Peek() == 2) stack.Pop(); else stack.Push(c);
	}
	return stack.Count == 0;
}
```