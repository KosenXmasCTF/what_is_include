FROM centos:centos7

RUN yum -y install openssh-server passwd gcc; yum clean all
RUN ssh-keygen -A

ADD ./what_is_include /home/what_is_include
RUN chmod 755 /home/what_is_include

RUN useradd guest -m

RUN echo "guest" | passwd --stdin guest

RUN echo "timeout 20 /home/what_is_include; exit" > ~guest/.bashrc

ENTRYPOINT ["/sbin/sshd", "-D"]



