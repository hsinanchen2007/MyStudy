```c# []
public bool IsNStraightHand(int[] hand, int W) {
        if (hand.Length % W != 0)
            {
                return false;
            }
            Array.Sort(hand);
            var count = hand.Length / W;
            var dict = new Dictionary<int, int>();
            for (var i = 0; i < hand.Length; i++)
            {
                var k = hand[i];
                if (dict.ContainsKey(k))
                {
                    dict[k]++;
                }
                else
                {
                    dict[k] = 1;
                }
            }
            while (dict.Keys.Count > 0)
            {
                var keys = dict.Keys.ToArray();
                var key = keys[0];
                for (var i = 0; i < W; i++)
                {
                    var t = key + i;
                    if (!dict.ContainsKey(t))
                    {
                        return false;
                    }
                    else
                    {
                        dict[t]--;
                        if (dict[t] == 0)
                        {
                            dict.Remove(t);
                        }
                    }

                }
            }
            return true;
    }
```

