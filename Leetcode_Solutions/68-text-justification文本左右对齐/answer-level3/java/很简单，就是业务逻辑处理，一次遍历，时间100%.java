```
public List<String> fullJustify(String[] words, int maxWidth) {
		List<String> list = new ArrayList<>();
		int cursor = 0;

		while (cursor < words.length) {
			int childCursor = cursor;
			int sumLength = 0;
			while (childCursor < words.length && sumLength + words[childCursor].length() <= maxWidth) {
				sumLength = sumLength + words[childCursor].length() + 1;
				childCursor++;
			}
			/**
			 * [cursor,childCursor)的区间的元素
			 */
			int size = childCursor - cursor;
			StringBuilder sb = new StringBuilder(maxWidth);

			if (childCursor == words.length) {
				/**
				 * 直接按照顺序左对齐
				 */
				int hadUseSpace = 0;
				while (cursor < childCursor) {
					hadUseSpace = hadUseSpace + 1 + words[cursor].length();
					sb.append(words[cursor]);
					if (hadUseSpace <= maxWidth)
						sb.append(' ');

					cursor++;
				}
				for (int j = 1; j <= maxWidth - hadUseSpace; j++)
					sb.append(' ');
				list.add(sb.toString());
				return list;

			}
			if (size > 1) {
				/**
				 * 字符串长度
				 */
				int charLength = sumLength - size;
				/**
				 * 空格长度
				 */
				int mod = (maxWidth - charLength) % (size - 1);
				int spaceLength = (maxWidth - charLength) / (size - 1);

				int i = cursor;
				boolean jiange = true;
				while (i < childCursor) {
					if (jiange) {
						sb.append(words[i]);
						i++;
						jiange = false;
					} else {
						int spaceSize = spaceLength;
						if (mod > 0) {
							spaceSize++;
							mod--;
						}
						for (int j = 0; j < spaceSize; j++)
							sb.append(' ');

						jiange = true;

					}

				}

			} else {
				int spaceLength = maxWidth - words[cursor].length();
				sb.append(words[cursor]);
				for (int j = 0; j < spaceLength; j++)
					sb.append(' ');
			}
			list.add(sb.toString());
			cursor = childCursor;

		}
		return list;

	}
```
