```
//此函数假设p1、p2对角，p3、p4对角
bool isSquare(int* p1, int* p2, int* p3, int* p4) {	
	int p1p3[2] = { p3[0] - p1[0], p3[1] - p1[1] };
	int p1p4[2] = { p4[0] - p1[0], p4[1] - p1[1] };
	int p2p3[2] = { p3[0] - p2[0], p3[1] - p2[1] };
	int p2p4[2] = { p4[0] - p2[0], p4[1] - p2[1] };
	//求边长长度
	int len13 = p1p3[0] * p1p3[0] + p1p3[1] * p1p3[1];
	int len14 = p1p4[0] * p1p4[0] + p1p4[1] * p1p4[1];
	int len23 = p2p3[0] * p2p3[0] + p2p3[1] * p2p3[1];
	int len24 = p2p4[0] * p2p4[0] + p2p4[1] * p2p4[1];
	//根据向量乘积，判断是否为直角
	int angle90Flag = p1p3[0] * p1p4[0] + p1p3[1] * p1p4[1];
	if ((len13 > 0) && (len13 == len14) && (len14 == len23) && (len23 == len24) && (angle90Flag == 0)) {
		return true;
	}
	return false;
}
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) {
	bool flag = 0; 
	//三种可能的对角顶点分布
	flag |= isSquare(p1, p2, p3, p4);
	flag |= isSquare(p1, p3, p2, p4);
	flag |= isSquare(p1, p4, p3, p2);
	return flag;
}
```
