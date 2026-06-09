def bitwiseComplement(N: int) -> int:
	return N ^ int(len(bin(N)[2:]) * '1', 2)