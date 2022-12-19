评论中找到的灵魂级算法，求字符串数组中的最大值与最小值，然后取最大最小值得公共前缀就是所求的公共前缀！


public static string LongestCommonPrefix(string[] strs)
{
    if (strs.Length <= 0) return "";
    string result = string.Empty;
    string strMax = strs.Max();
    string strMin = strs.Min();
    int i = 0;
    for (; i < strMin.Length; i++)
    {
        if (strMax[i] != strMin[i]) { result = strMin.Substring(0, i); break; }
    }
    if (i == strMin.Length) result = strMin;
    return result;
}