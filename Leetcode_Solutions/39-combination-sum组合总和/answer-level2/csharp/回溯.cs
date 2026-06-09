### 解题思路
关于如何解决重复的问题还没有很好的想法

### 代码

```csharp
public class Solution {
  	int[] data;
		List<int> record;
		IList<IList<int>> result;

		public IList<IList<int>> CombinationSum (int[] candidates, int target)
		{
			data = candidates;

			record = new List<int> ();
			result = new List<IList<int>> ();

			FindNum (target);
			return result;
		}

		void FindNum (int tar)
		{
			if (tar == 0 && !Repeat ())
			{
				result.Add (CopyList ());
			}

			if (tar < 0)
			{
				return;
			}
			for (int i = 0; i < data.Length; i++)
			{
				if (data[i] <= tar)
				{
					record.Add (data[i]);
					FindNum (tar - data[i]);
					record.Remove (data[i]);
				}
			}
		}

		List<int> CopyList ()
		{
			List<int> res = new List<int> ();

			foreach (var item in record)
			{
				res.Add (item);
			}
			return res;
		}

		bool Repeat ()
		{
				record.Sort ();
			foreach (var item in result)
			{
				if (item.Count == record.Count)
				{
					bool same = true;
					for (int i = 0; i < record.Count; i++)
					{
						if (record[i] != item[i])
						{
							same = false;
							break;
						}
					}
					if (same) { return true; }
				}
			}
			return false;
		}
}
```