import java.util.Scanner;

public class Main {
	
		// N (1 <= N <= 15)	- ���� �� �ִ� Ƚ��
		// Ti <= 5 			- �ɸ��� �ϼ�
		// 1 <= P1 <= 1000	- �Ͽ� ���� ����
		static int N = 0;
		static int[] T = new int[15];
		static int[] P = new int[15];
		static int max = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		
		for(int i = 0 ; i < N; i ++) {
			T[i] = input.nextInt();
			P[i] = input.nextInt();
		}
		input.close();
		
		work(1, 0);
		System.out.println("��� : "+ max);
	}
	
	static void work(int day, int totalP) {
		// �ִ� �ϼ� �ѱ�� ����
		if(day > N+1) {
			return;
		}
		
		// �ִ񰪺��� ũ�� �ִ� ����
		if(day == N+1) {
			if(totalP > max) {
				max = totalP;
				return;
			}
		}
		
		// ����� �ϴ� ���, ���ǹ��� ����ϼ��� �Ѿ Ž���Ϸ��� ��� ����
		if(day <= N) {
		work(day+T[day-1], totalP + P[day-1]);
		}
		
		// ����� ���� �ʰ� �Ϸ縦 ��������� ���
		work(day+1, totalP);
	}
	
	
}
