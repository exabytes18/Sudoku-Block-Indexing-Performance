public class Main {
	public static void main(String[] args) {
		int x = 0;
		int numIterations = 10000000;

		long start = System.nanoTime();
		for (int i = 0; i < numIterations; i++) {
			for (int j = 0; j < 81; j++) {
				x += (j - 9 * (j / 9)) / 3 + 3 * (j / 27);
			}
		}
		long end = System.nanoTime();

		System.out.println("Summation: " + x);
		System.out.printf("%d iterations: %.3fs\n", numIterations, (end - start) / 1e9);
	}
}

