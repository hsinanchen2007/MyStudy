```
public class Solution {
    List<string> signalList = new List<string> { "+", "-", "*" };
    public IList<int> DiffWaysToCompute(string input)
    {
        string magicString = "${0}$";
        foreach (string signal in signalList)
        {
            input = input.Replace(signal, string.Format(magicString, signal));
        }
        string[] inputList = input.Split(@"$");
        return Compute(inputList, 0, inputList.Length);
    }

    private IList<int> Compute(string[] inputList, int start, int end)
    {
        if (end - start == 1)
        {
            return new List<int> { int.Parse(inputList[start]) };
        }
        IList<int> res = new List<int>();
        IList<int> left;
        IList<int> right;
        for (int i = start; i < end; i++)
        {
            if (signalList.Contains(inputList[i]))
            {
                left = Compute(inputList, start, i);
                right = Compute(inputList, i + 1, end);
                foreach (int numLeft in left)
                {
                    foreach (int numRight in right)
                    {
                        res.Add(Process(numLeft, numRight, inputList[i]));
                    }
                }
            }
        }
        return res;
    }

    private int Process(int numLeft, int numRight, string signal)
    {
        if (signal.Equals("+"))
        {
            return numLeft + numRight;
        }
        else if (signal.Equals("-"))
        {
            return numLeft - numRight;
        }
        else
        {
            return numLeft * numRight;
        }
    }
}
```