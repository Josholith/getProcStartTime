#include <time.h>
#include <procinfo.h>

main(argc, argv)
char *argv[];
{
  struct procentry64 psinfo;
  pid_t pid;
  if (argc > 1) {
    pid = atoi(argv[1]);
  }
  else {
    printf("Usage : getProcStartTime pid\n");
    return 1;
  }
  if (getprocs64(&psinfo, sizeof(struct procentry64), NULL, sizeof(struct fdsinfo64) , &pid, 1) > 0) {
    time_t result;
    result = psinfo.pi_start;
    struct tm* brokentime = localtime(&result);
    printf("%s", asctime(brokentime)); 
    return 0;
  } else {
    perror("getproc64");
    return 1;
  }
}
