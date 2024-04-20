#include <stdio.h>
#include <stdlib.h>

// -- 원형 큐 코드 시작 --


#define MAX_QUEUE_SIZE 5

// 큐의 최대 크기를 정의
typedef int element; // 큐에 저장할 int형 데이터를 선언할 때, 구분하기 쉽도록 별칭을 지정.


// 큐 타입
typedef struct {
    element data[MAX_QUEUE_SIZE]; // 큐의 데이터를 저장하는 배열
    
    int front, rear; // 큐의 시작과 끝을 나타내는 포인터
    
} QueueType; // 큐의 구조체 정의



void error(char *message) { // 오류가 발생했을 때 메시지를 출력하는 함수

    fprintf(stderr, "%s\n", message);
    exit(1);
    
} // 오류 함수



void init_queue(QueueType *q) { // 큐를 초기화하는 함수

    q->front = q->rear = 0; // 큐의 시작과 끝을 초기화하여 빈 큐로 설정
    
}



int is_empty(QueueType *q) { // 큐가 비어있는지 확인하는 함수

    return (q->front == q->rear);
    
} // 공백 상태 검출 함수



int is_full(QueueType *q) { // 큐가 꽉 찼는지 확인하는 함수

    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
    
} // 포화 상태 검출 함수



void queue_print(QueueType *q) { // 큐의 내용을 출력하는 함수

    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear); // 큐의 시작과 끝을 출력
    if (!is_empty(q)) { // 큐가 비어있지 않다면
        int i = q->front; // 시작부터 시작
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE); // 한 칸씩 전진하며 출력
            printf("%d |", q->data[i]); // 큐의 내용을 출력
            if (i == q->rear) // 만약 마지막까지 도달했다면
                break; // 종료
        } while (i != q->front); // 시작으로 돌아올 때까지 반복
    }
    printf("\n");
    
} // 원형 큐 출력 함수



void enqueue(QueueType *q, element item) { // 큐에 데이터를 추가하는 함수

    if (is_full(q)) // 큐가 꽉 찼다면
        error("큐가 포화상태입니다"); // 오류 메시지 출력
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // rear를 한 칸 뒤로 이동
    q->data[q->rear] = item; // 새로운 데이터를 큐에 추가
    
} // 삽입 함수 



element dequeue(QueueType *q) { // 큐에서 데이터를 삭제하고 반환하는 함수

    if (is_empty(q)) // 큐가 비어있다면
        error("큐가 공백상태입니다"); // 오류 메시지 출력
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front를 한 칸 뒤로 이동
    return q->data[q->front]; // 삭제된 데이터 반환
    
} // 삭제 함수



element peek(QueueType *q) { // 큐의 첫 번째 데이터를 확인하는 함수
    if (is_empty(q)) // 큐가 비어있다면
        error("큐가 공백상태입니다"); // 오류 메시지 출력
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE]; // 큐의 첫 번째 데이터 반환
}

// -- 원형 큐 코드 끝 -- 




int main(void) {

    QueueType queue; // 큐 변수 선언
    int element; // 사용자 입력을 저장할 변수 선언
    init_queue(&queue); // 큐 초기화

    printf("\n\n-- 데이터 추가 단계 --\n\n");
    while (!is_full(&queue)) { // 큐가 꽉 찰 때까지 반복
        printf("정수를 입력하세요 : "); // 사용자에게 입력 요청
        scanf("%d", &element); // 사용자 입력을 변수에 저장
        enqueue(&queue, element); // 큐에 데이터 추가
        queue_print(&queue); // 큐의 내용 출력
    }
    printf("\n\n큐는 포화상태입니다.\n\n");


    printf("\n\n\n-- 데이터 삭제 단계 --\n\n");
    while (!is_empty(&queue)) { // 큐가 비어있지 않을 때까지 반복
        element = dequeue(&queue); // 큐에서 데이터를 삭제하고 변수에 저장
        printf("꺼내진 정수: %d\n", element); // 삭제된 데이터 출력
        queue_print(&queue); // 큐의 내용 출력
    }
    printf("\n\n큐는 공백상태입니다.\n");

    return 0;
    
}

