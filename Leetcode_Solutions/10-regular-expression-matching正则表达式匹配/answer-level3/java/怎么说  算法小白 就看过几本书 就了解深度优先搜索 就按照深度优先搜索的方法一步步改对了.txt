对于算法确实不太精通,从自己已经了解的算法,进行计算.
```
	public boolean isMatch(String s, String p) {
		if (s.equals("") && p.equals(""))
			return true;
		if (s.equals(p))
			return true;
		int plen = p.length();
		List<P> list = new LinkedList<>();
		//对正则式子进行分解
		for (int i = 0; i < plen; i++) {
			if ((p.charAt(i) >= 'a' && p.charAt(i) <= 'z') || p.charAt(i) == '.') {
				if (i + 1 < plen) {
					if (p.charAt(i + 1) != '*') {
						list.add(new P(p.charAt(i), false));
					} else {
						list.add(new P(p.charAt(i), true));
						i++;
					}
				} else {
					list.add(new P(p.charAt(i), false));
				}
			}
		}
		list = new ArrayList<P>(list);
		int len = list.size();
		return step(s, 0, list, 0, len);
	}

	/**
	 * 匹配规律 
	 * 符合当前正则,不符合下一个正则,进行当前正则匹配. 
	 * 不符合当前正则,不符合下一个正则,进行下一个正则.
	 * 符合当前正则,符合下一个正则,对每一个符合下一个正则的进行探.
	 * 不符合当前正则,符合下一个正则,匹配失败直接结束.
	 * 
	 * @param s		待解析的字符串
	 * @param index	待解析字符串的匹配位数
	 * @param list	正则式的分解
	 * @param step 	正则式分解进行的步数
	 * @param lilen	正则式分解后的所有步数
	 * @return
	 */

	public boolean step(String s, int index, List<P> list, int step, int lilen) {
		// 正则式是否匹配完毕
		if (step >= lilen) {
			//正则式匹配完毕但字符串匹配没有结束
			if (index != s.length()) {
				return false;
			}
			return true;
		}
		// 是否字符串匹配结束
		if (index == s.length()) {
			//字符串匹配结束后,但是正则式有剩余且不是全位*的时候
			if (step != lilen) {
				boolean flag = true;
				for (; step < lilen; step++) {
					if (!list.get(step).isStar) {
						flag = false;
						break;
					}
				}
				return flag;
			}
			return true;
		}

		P p = list.get(step);
		// 符合当前正则 或者当前正则含有*
		if (p.ch == s.charAt(index) || p.ch == '.' || p.isStar) {
			// 有*的时候
			if (p.isStar) {
				// 如果还有下一步
				if (step + 1 < lilen) {
					// 获取下一步的匹配
					P next = list.get(step + 1);
					int t=index;
					for (t = index; t < s.length(); t++) {
						// 当前符合下一步的匹配 进入下一步匹配
						if (s.charAt(t) == next.ch || next.ch == '.' || next.isStar) {

								if (step(s, t, list, step + 1, lilen)) {
									return true;
								}
						}
						//符合当前匹配 
						if (s.charAt(t) == p.ch || p.ch == '.') {

						} else {
							//既不符合下一次 也不符合当前
							return false;
						}
					}
					//字符串匹配当前的  且字符串匹配完毕 但正则式还有剩余
					if (step(s, t, list, step + 1, lilen)) {
						return true;
					}
				}
				// 已经没有下一步了
				else {
					boolean flag = true;
					// 校验剩下的式子是否和正则式匹配
					while (index < s.length()) {
						if (!(s.charAt(index++) == p.ch || p.ch == '.')) {
							flag = false;
							break;
						}
					}
					if (flag) {
						return step(s, index, list, step + 1, lilen);
					} else {
						return false;
					}
				}
			}
			// 没有* 已经匹配成功进入下一阶段
			else {
				return step(s, index + 1, list, step + 1, lilen);
			}
		}
		return false;
	}

	class P {
		public char ch;
		//是否有*
		public boolean isStar;

		public P(char ch, boolean isStar) {
			this.ch = ch;
			this.isStar = isStar;
		}

		@Override
		public String toString() {
			if (isStar)
				return ch + "*";
			else
				return ch + "";
		}
	}
```
