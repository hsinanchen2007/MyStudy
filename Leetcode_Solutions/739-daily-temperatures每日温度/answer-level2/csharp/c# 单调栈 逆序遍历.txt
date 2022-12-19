public class Solution {
    public int[] DailyTemperatures(int[] T) {
        int len=T.Length;
        Stack<int> stack = new Stack<int>();
        int[] result = new int[len];
        for (int i = len - 1; i >= 0; i--)
        {
            while (stack.Count != 0 && T[stack.Peek()] <= T[i])
                    stack.Pop();
            if(stack.Count!=0)        
                result[i] = stack.Peek() - i;
            stack.Push(i);    
        }
        return result;
    }
}